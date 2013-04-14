#define BOOST_ALL_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_LOG_LEVEL message

#include <boost/test/unit_test.hpp>

#include "heap.h"

using namespace boost::unit_test;
using namespace std;

BOOST_AUTO_TEST_SUITE(TestHeap)

BOOST_AUTO_TEST_CASE(testIsEmpty) {
  BOOST_TEST_MESSAGE("Testing that isEmpty works");
  Heap<int> heap;
  BOOST_REQUIRE(heap.isEmpty());
  heap.addElement(5);
  BOOST_REQUIRE(!heap.isEmpty());
  heap.deleteMinElement();
  BOOST_REQUIRE(heap.isEmpty());
}

BOOST_AUTO_TEST_CASE(deleteMinElement) {
  BOOST_TEST_MESSAGE("Testing that printHeap() works");
  Heap<int> heap;
  heap.addElement(1);
  heap.addElement(2);
  heap.addElement(104);
  try {
    BOOST_REQUIRE(heap.deleteMinElement() == 1);
  } catch(exception const& ex) {
    BOOST_TEST_MESSAGE(ex.what());
  } try {
    BOOST_REQUIRE(heap.deleteMinElement() == 2);
  } catch(exception const& ex) {
    BOOST_TEST_MESSAGE(ex.what());
  } try {
    BOOST_REQUIRE(heap.deleteMinElement() == 104);
  } catch(exception const& ex) {
    BOOST_TEST_MESSAGE(ex.what());
  } try {
    BOOST_REQUIRE(heap.deleteMinElement() != 0);
  } catch(exception const& ex) {
    BOOST_TEST_MESSAGE(ex.what());
  }
}

BOOST_AUTO_TEST_SUITE_END()
