#include "unity.h"
#include "fsm.h"

#include "mock_eventos.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_fsmInit(void) {
   fsmInit();
   TEST_ASSERT_EQUAL_HEX32(ESTADO_INICIAL, estadoFsm);
}
/*
void test_fsmCrear (void) {

    fsmInit();
    fsm();
    
    TEST_ASSERT_EQUAL_HEX32(ESTADO_ESPERO_SINC, estadoFsm);

}
*/
void test_fsmPrimerEstado(void) {
    // espero recibir primer comando de arroba para cambiar de estado
    fsmInit();
    TEST_ASSERT_EQUAL_HEX32(ESTADO_INICIAL, estadoFsm);
    recibirComando_ExpectAndReturn('@');
    fsm();
    TEST_ASSERT_EQUAL_HEX32(ESTADO_ESPERO_START, estadoFsm);
}

