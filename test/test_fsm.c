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
    TEST_ASSERT_EQUAL_HEX32(ESTADO_ESPERO_SINC, estadoFsm);

    // Testeo que no se vaya a otro estado con comandos validos
    recibirComando_ExpectAndReturn('S');
    fsm();
    TEST_ASSERT_EQUAL_HEX32(ESTADO_ESPERO_SINC, estadoFsm);
    recibirComando_ExpectAndReturn('E');
    fsm();
    TEST_ASSERT_EQUAL_HEX32(ESTADO_ESPERO_SINC, estadoFsm);
    recibirComando_ExpectAndReturn('P');
    fsm();
    TEST_ASSERT_EQUAL_HEX32(ESTADO_ESPERO_SINC, estadoFsm);


    // Testeo primer transición
    recibirComando_ExpectAndReturn('@');
    enviarRespuesta_Expect("U0000");
    fsm();
    TEST_ASSERT_EQUAL_HEX32(ESTADO_ESPERO_START, estadoFsm);

}

void test_fsmSegundoEstado(void) {

    // inicializo la fsm
    fsmInit();

    // mando al segundo estado
    recibirComando_ExpectAndReturn('@');
    enviarRespuesta_Expect("U0000");
    fsm();

    // Testeo que no se vaya a otro estado con comandos validos
    recibirComando_ExpectAndReturn('E');
    fsm();
    TEST_ASSERT_EQUAL_HEX32(ESTADO_ESPERO_START, estadoFsm);
    recibirComando_ExpectAndReturn('P');
    fsm();
    TEST_ASSERT_EQUAL_HEX32(ESTADO_ESPERO_START, estadoFsm);
    
    // Pruebo transicion hacia si mismo
    recibirComando_ExpectAndReturn('@');    
    enviarRespuesta_Expect("U0000");
    fsm();
    TEST_ASSERT_EQUAL_HEX32(ESTADO_ESPERO_START, estadoFsm);

    // Pruebo transicion hacia 3er estado
    recibirComando_ExpectAndReturn('S');    
    fsm();
    TEST_ASSERT_EQUAL_HEX32(ESTADO_ETAPA_ONLINE, estadoFsm);  

}







