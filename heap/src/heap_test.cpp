#define BOOST_ALL_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_LOG_LEVEL message

#include <boost/test/unit_test.hpp>
#include <string>
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
  BOOST_CHECK_EQUAL(heap.deleteMinElement(), 1);
  BOOST_CHECK_EQUAL(heap.deleteMinElement(), 2);
  BOOST_CHECK_EQUAL(heap.deleteMinElement(), 104);
  try {
    heap.deleteMinElement();
    BOOST_FAIL("Should throw exception!");
  } catch(exception const& ex) {
    BOOST_CHECK_EQUAL(string(ex.what()), "The heap is empty!");
  }
}

BOOST_AUTO_TEST_CASE(testWithStrings) {
  BOOST_TEST_MESSAGE("Testing that program works with Strings.");
  Heap<string> heap;
  BOOST_REQUIRE(heap.isEmpty());
  heap.addElement("Hello!");
  BOOST_REQUIRE(!heap.isEmpty());
  heap.deleteMinElement();
  BOOST_REQUIRE(heap.isEmpty());
  heap.addElement("Moscow");
  heap.addElement("Nizhniy Novgorod");
  heap.addElement("Palo Alto");
  heap.printHeap();
}

BOOST_AUTO_TEST_CASE(addElement) {
  Heap<int> heap;
  heap.addElement(1);
  heap.addElement(2);
  heap.addElement(104);
  heap.addElement(1342);
  heap.addElement(1345);
  BOOST_CHECK_EQUAL(heap.deleteMinElement(), 1);
  BOOST_CHECK_EQUAL(heap.deleteMinElement(), 2);
  BOOST_CHECK_EQUAL(heap.deleteMinElement(), 104);
  BOOST_CHECK_EQUAL(heap.deleteMinElement(),1342);
  BOOST_CHECK_EQUAL(heap.deleteMinElement(),1345);
}

BOOST_AUTO_TEST_SUITE_END()
