#include <cstdint>

/*
 * Monolithic XISF file header.
 */
struct XISFMonolithicFileHeader
{
   uint8_t  magic[ 8 ];   // 'XISF0100'
   uint32_t headerLength; // length in bytes of the XML file header
   uint32_t reserved = 0; // reserved - must be zero

   /*
    * Constructs a monolithic XISF file header with the specified XML header
    * length in bytes.
    */
   XISFMonolithicFileHeader( uint32_t _headerLength )
   {
      magic[0] = 'X'; magic[1] = 'I'; magic[2] = 'S'; magic[3] = 'F';
      magic[4] = '0'; magic[5] = '1'; magic[6] = '0'; magic[7] = '0';
      headerLength = _headerLength;
   }

   /*
    * Returns true if this is a valid monolithic XISF file header.
    */
   bool IsValid() const
   {
      return magic[0] == 'X' && magic[1] == 'I' && magic[2] == 'S' && magic[3] == 'F' &&
             magic[4] == '0' && magic[5] == '1' && magic[6] == '0' && magic[7] == '0' &&
             headerLength >= 65; // minimum length of an empty header from "<?xml..." to </xisf>
   }
};
