#include <cstdint>

/*
 * XISF block index element.
 */
struct XISFBlockIndexElement
{
   uint64_t uniqueId;                    // unique block index element identifier
   uint64_t blockPosition = 0;           // block byte offset from file beginning
   uint64_t blockLength = 0;             // stored block length in bytes
   uint64_t uncompressedBlockLength = 0; // uncompressed block length in bytes
   uint64_t reserved = 0;                // reserved - must be zero

   /*
    * Constructs a free block index element.
    *
    * The _uniqueId argument must be unique within the XISF data blocks file to
    * which this block index pertains.
    */
   XISFBlockIndexElement( uint64_t _uniqueId ) : uniqueId( _uniqueId )
   {
   }

   /*
    * Returns true if this is a free block index element.
    */
   bool IsFree() const
   {
      return blockPosition == 0;
   }
};
