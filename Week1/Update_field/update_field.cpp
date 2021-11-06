#include "airline_ticket.h"
#include "test_runner.h"
#include <sstream>
#include <map>
#include <iostream>
using namespace std;
bool operator<(const Date& lhs, const Date& rhs) {
  return std::tie(lhs.year, lhs.month, lhs.day)
      < std::tie(rhs.year, rhs.month, rhs.day);
}

bool operator<(const Time& lhs, const Time& rhs) {
  return std::tie(lhs.hours, lhs.minutes)
      < std::tie(rhs.hours, rhs.minutes);
}

bool operator==(const Date& lhs, const Date& rhs) {
  return std::tie(lhs.year, lhs.month, lhs.day)
      == std::tie(rhs.year, rhs.month, rhs.day);
}

bool operator==(const Time& lhs, const Time& rhs) {
  return std::tie(lhs.hours, lhs.minutes)
      == std::tie(rhs.hours, rhs.minutes);
}

std::ostream& operator<<(std::ostream& out, const Date& rhs) {
  out << rhs.year << "-" << rhs.month << "-" << rhs.day;
  return out;
}

std::ostream& operator<<(std::ostream& out, const Time& rhs) {
  out << rhs.hours << ":" << rhs.minutes;
  return out;
}

std::istream& operator >>(std::istream& is, Time&time){
    is >> time.hours;
    is.ignore(1);
    is >> time.minutes;
    return is;
}
std::istream& operator >>(std::istream& is, Date&d){
    is >> d.year;
    is.ignore(1);
    is >> d.month;
    is.ignore(1);
    is >> d.day;
    return is;
}
#define UPDATE_FIELD(ticket, field, values) \
  {                                         \
    auto it = values.find(#field);          \
    if (it != values.end()) {               \
      istringstream is(it->second);         \
      is >> ticket.field;                   \
    }                                       \
  }
void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}