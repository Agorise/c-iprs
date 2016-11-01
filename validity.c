#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include "iprs.h"
#include "validity.h"
#include "sign.h"

Record* MakeRecord(uint8_t* value, uint8_t* authorKey) {
   struct timeval tv;
   Record* r = calloc(1, sizeof(Record));

   if (r) {
      if (gettimeofday(&tv, NULL) != 0) {
          // gettimeofday failed, cannot continue.
          return NULL;
      }
      r->Value = value;

      /* establish an expiration date */
      r->Expires = tv.tv_sec + EXPIRATION_SECS;

      /* cryptographically sign the record */
      r->Signature = authorKey_Sign(signablePart(r));
   }

   return r;
}

int VerifyRecord(Record* r, uint8_t* authorKey) {
   /* always check the signature first */
   int sigok = authorKey_Verify(r->Signature, signablePart(r));
   struct timeval tv;

   if (!sigok || !r) {
      return FALSE; /* sig did not check out! forged record? */
   }

   if (gettimeofday(&tv, NULL) != 0) {
       // gettimeofday failed, cannot continue.
       return FALSE;
   }

   /* check the expiration. */
   if (r->Expires < tv.tv_sec) {
      return FALSE; /* not valid anymore :( */
   }

   /* everything seems ok! */
   return TRUE;
}
