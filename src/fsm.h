/** @brief defino estado inicial */
#define ESTADO_INICIAL  ESTADO_ESPERO_SINC
#define ESTADO_ESPERO_SINC  0x100

/** @brief prototipo de la funcion de inicializacion de la fsm */
void fsmInit(void);
/** @brief prototipo de la funcion de la fsm */
void fsm (void);

/** @brief variable de estado de la fsm */
extern uint32_t estadoFsm;



