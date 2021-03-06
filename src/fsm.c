#include <stdint.h>
#include <fsm.h>

#include "eventos.h"
/** @brief prototipo de la funcion de inicializacion de la fsm */
void fsmInit(void);

/** @brief variable de estado de la fsm */
uint32_t estadoFsm;

/**
 * @fn void fsmInit(void);
 *
 * @brief funcion que inicializa la máquina de estados
 */

void fsmInit(void) {

    estadoFsm = ESTADO_INICIAL;
    return;

}


/**
 * @fn void fsm(void);
 *
 * @brief maquina de estados
 */

void fsm (void) {
    int8_t comando;

    comando = recibirComando();

    switch(estadoFsm) {

    case ESTADO_ESPERO_SINC:    

        if(comando == '@'){
            estadoFsm = ESTADO_ESPERO_START;
            enviarRespuesta("U0000");
        }
        else
            estadoFsm = ESTADO_ESPERO_SINC;

        break;

    case ESTADO_ESPERO_START:

        if(comando == '@'){
            estadoFsm = ESTADO_ESPERO_START;
            enviarRespuesta("U0000");
        }
        else if(comando == 'S') {
            estadoFsm = ESTADO_ETAPA_ONLINE;    
        }
        break;

    case ESTADO_ETAPA_ONLINE:

        if(comando == 'E') {
            estadoFsm = ESTADO_ESPERO_SINC;
            enviarRespuesta("P@@@@@");
        }
        else if (comando == 'P') {
            estadoFsm = ESTADO_ESPERO_SINC;
            enviarRespuesta("P@@@@@");
        }

        break;

    }
    return;
}

