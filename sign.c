#include <stdlib.h>
#include <stdint.h>
#include "iprs.h"
#include "sign.h"

uint8_t* signablePart(Record *r) {
   uint8_t* sigbuf = NULL;
   /* TODO */
   return sigbuf;
}

uint8_t* authorKey_Sign(uint8_t *v) {
   uint8_t* sign = NULL;
   /* TODO */
   return sign;
}

int authorKey_Verify(uint8_t *sign, uint8_t *value) {
   /* TODO */
   return TRUE;
}
