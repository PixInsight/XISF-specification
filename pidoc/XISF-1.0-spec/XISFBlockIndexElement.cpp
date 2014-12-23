#include <cstdint>

/*
 * XISF block index element.
 */
struct XISFBlockIndexElement
{
   uint64_t uniqueId;                // unique block index element identifier
   uint64_t blockPosition;           // block byte offset from file beginning
   uint64_t blockLength;             // stored block length in bytes
   uint64_t uncompressedBlockLength; // uncompressed block length in bytes
   uint64_t reserved;                // reserved - must be zero

   /*
    * Constructs a free block index element.
    */
   XISFBlockIndexElement() : uniqueId( RandomUI64() )
   {
      blockPosition = blockLength = uncompressedBlockLength = reserved = 0;
   }

   /*
    * Returns true if this is a free block index element.
    */
   bool IsFree() const
   {
      return blockPosition == 0;
   }

private:

   /*
    * Returns a pseudo-random 64-bit unsigned integer.
    */
   static uint64_t RandomUI64()
   {
      ...
   }
};
