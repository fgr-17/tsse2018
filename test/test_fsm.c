#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_fsmInit(void) {
   fsmInit();
   TEST_ASSERT_EQUAL_HEX32(ESTADO_INICIAL, estadoFsm);
}
