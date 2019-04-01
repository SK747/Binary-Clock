#include "config/power.h"
#include "config/stream.h"
#include "config/usart.h"

extern "C" {
#include "binaryclock.h"
}

Rtc<RtcLseClockFeature> *_rtc;

class UsartRXInterrupts {

public:
  UsartPollingOutputStream outputStream;

  UsartRXInterrupts() : _usart(57600), outputStream(_usart) {}



  void run() {
    this->init();
    for (;;) {
      this->tick();
    }
  }

  void init() {
    init_binaryclock();

    Nvic::initialise();

    outputStream << "Hello\n";
    outputStream << "Yes "
                 << (_rtc->passed() ? "passed\n" : "did not pass\n");
    var_display("time");
  }

  void tick() {
    if (_usart.dataAvailable()) {
      char c[] = {_usart.receive()};
      _usart.send(c[0]); // again
      parse_binaryclock(c, 1, c[0] == '\n');
      if (c[0] == '\n') {
        init_binaryclock();
      }
    }
  }
};

UsartRXInterrupts *usart;

void var_set(const char *name, uint16_t value) {
  std::string h("h"), m("m"), s("s");
  bool set_time = false;
  uint8_t hours, minutes, seconds, am_pm;
  _rtc->getTime(hours, minutes, seconds, am_pm);
  if (h.compare(name) == 0) {
    hours = value;
    set_time = true;
  } else if (m.compare(name) == 0) {
    minutes = value;
    set_time = true;
  } else if (s.compare(name) == 0) {
    seconds = value;
    set_time = true;
  }
  if (set_time) {
    _rtc->setTime(hours, minutes, seconds, am_pm);
  }
}

void time_set(const char *variable, uint16_t time[]) {
  if (std::string("time").compare(variable) == 0) {
    _rtc->setTime(time[0], time[1], time[2]);
    usart->outputStream << "Time set\n";
  }
}

void var_display(const char *name) {
  std::string time("time"), h("h"), m("m"), s("s");
  if (time.compare(name) == 0) {
    auto out = usart->outputStream;
    uint8_t time[4];

    char buffer[4];

    _rtc->getTime(time[0], time[1], time[2], time[3]);
    out << name << "=";

    for (int i = 0; i < 3; i++) {
      itoa(time[i], buffer, 10);
      if (time[i] < 10) {
        out << "0";
      }
      out << buffer;
    }

    out << "\n";
  }
}



int main() {

  MillisecondTimer::initialise();

  RCC_LSEDriveConfig(RCC_LSEDrive_Low);

  _rtc = &rtc;

  UsartRXInterrupts commands;
  usart = &commands;

  usart->init();

  bool testpattern = false;

  while (true) {
    usart->tick();

    uint8_t hours, minutes, seconds, am_pm;
    _rtc->getTime(hours, minutes, seconds, am_pm);

    if (!testpattern || seconds % 3 == 0) {
      sources.resetAll();
      sinks.setAll();
      *sinks.getResetRegister() = hours << 10;
      sources[8].set();
      MillisecondTimer::delay(2);
    }

    if (!testpattern || seconds % 3 == 1) {
      sources.resetAll();
      sinks.setAll();
      *sinks.getResetRegister() = minutes << 10;
      sources[10].set();
      MillisecondTimer::delay(2);
    }

    if (!testpattern || seconds % 3 == 2) {
      sources.resetAll();
      sinks.setAll();
      *sinks.getResetRegister() = seconds << 10;
      sources[11].set();
      MillisecondTimer::delay(2);
    }
  }

  // not reached
  return 0;
}
