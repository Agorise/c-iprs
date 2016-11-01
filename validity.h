#ifndef VALIDITY_H
   #define VALIDITY_H

   #define EXPIRATION_SECS	(24 * 60 * 60)	/* Record valide for a day */

   uint8_t* signablePart(Record *r);
   Record* MakeRecord(uint8_t* value, uint8_t* authorKey);
   int VerifyRecord(Record* rec, uint8_t* authorKey);
#endif /* VALIDITY_H */
