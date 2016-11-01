#ifndef IPRS_H
   #define IPRS_H

   #define TRUE			1
   #define FALSE		0

   typedef struct Record_struct {
      uint8_t*    Value;
      uint32_t    Expires;
      uint8_t*    Signature;
   } Record;
#endif /* IPRS_H */
