#ifndef SIGN_H
   #define SIGN_H
   uint8_t* signablePart(Record *r);

   uint8_t* authorKey_Sign(uint8_t *v);

   int authorKey_Verify(uint8_t *sign, uint8_t *value);
#endif /* SIGN_H */
