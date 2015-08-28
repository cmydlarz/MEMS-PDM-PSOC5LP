#include "cytypes.h"
#include "Droop_Filter.h"

const uint32 CYCODE Droop_Filter_control[] = 
{
    0x25001320u,      0x26801761u,      0x26800001u,      0x26800001u,  
    0x26800400u,      0x26800965u,      0x26800001u,      0x26800400u,  
    0x26800971u,      0x26800001u,      0x26800EE0u,      0x26800CC2u,  
    0x06800002u,      0x6D188765u,      0x7F180221u,      0x3E180964u,  
    0x26800000u,      0x26800003u,      0x26801320u,      0x26800CC8u,  
    0x26800EE6u,      0x26800AAAu,      0x26801761u,      0x26800898u,  
    0x6D80067Au,      0x2F800678u,      0x6F100220u,      0x26808000u,  
    0x6F800220u,      0x26808000u,      0x6F800220u,      0x6F800220u,  
    0xFE401A21u,      0x26860000u,      0x66102202u,      0x6E108000u,  
    0x26808201u,      0x26800EECu,      0x26800CCEu,      0x06800000u,  
    0x6D188771u,      0x7F180221u,      0x3E180970u,      0x26800000u,  
    0x26800001u,      0x26801320u,      0x26800CD4u,      0x26800EF2u,  
    0x26800AB6u,      0x26801761u,      0x26800898u,      0x6D80067Au,  
    0x2F800678u,      0x6F100220u,      0x26808000u,      0x6F800220u,  
    0x26808000u,      0x6F800220u,      0x6F800220u,      0xFE401A21u,  
    0x26860000u,      0x66102202u,      0x6E108000u,      0x26808201u,  

};

const uint32 CYCODE Droop_Filter_data_a[] = 
{
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000800u,  

};

const uint32 CYCODE Droop_Filter_data_b[] = 
{
    0x00FFF293u,      0x00FFEEAEu,      0x00000CF5u,      0x00001B0Du,  
    0x00FFEE03u,      0x00FFD09Cu,      0x0000196Au,      0x00004ABDu,  
    0x00FFE00Cu,      0x00FF8E27u,      0x000027A9u,      0x0000A582u,  
    0x00FFD216u,      0x00FF150Fu,      0x000032DEu,      0x000146A3u,  
    0x00FFCC2Eu,      0x00FE3D95u,      0x00002E13u,      0x00026DEAu,  
    0x00FFE5D2u,      0x00FC94ABu,      0x00FFE639u,      0x00050C30u,  
    0x0000AC3Fu,      0x00F7ADF0u,      0x00FD0EB5u,      0x00126C12u,  
    0x001F1204u,      0x00126C12u,      0x00FD0EB5u,      0x00F7ADF0u,  
    0x0000AC3Fu,      0x00050C30u,      0x00FFE639u,      0x00FC94ABu,  
    0x00FFE5D2u,      0x00026DEAu,      0x00002E13u,      0x00FE3D95u,  
    0x00FFCC2Eu,      0x000146A3u,      0x000032DEu,      0x00FF150Fu,  
    0x00FFD216u,      0x0000A582u,      0x000027A9u,      0x00FF8E27u,  
    0x00FFE00Cu,      0x00004ABDu,      0x0000196Au,      0x00FFD09Cu,  
    0x00FFEE03u,      0x00001B0Du,      0x00000CF5u,      0x00FFEEAEu,  
    0x00FFF293u,      0x004E071Du,      0x00B1F8E3u,      0x00000000u,  
    0x003FDFDDu,      0x00000000u,      0x00FFF293u,      0x00FFEEAEu,  
    0x00000CF5u,      0x00001B0Du,      0x00FFEE03u,      0x00FFD09Cu,  
    0x0000196Au,      0x00004ABDu,      0x00FFE00Cu,      0x00FF8E27u,  
    0x000027A9u,      0x0000A582u,      0x00FFD216u,      0x00FF150Fu,  
    0x000032DEu,      0x000146A3u,      0x00FFCC2Eu,      0x00FE3D95u,  
    0x00002E13u,      0x00026DEAu,      0x00FFE5D2u,      0x00FC94ABu,  
    0x00FFE639u,      0x00050C30u,      0x0000AC3Fu,      0x00F7ADF0u,  
    0x00FD0EB5u,      0x00126C12u,      0x001F1204u,      0x00126C12u,  
    0x00FD0EB5u,      0x00F7ADF0u,      0x0000AC3Fu,      0x00050C30u,  
    0x00FFE639u,      0x00FC94ABu,      0x00FFE5D2u,      0x00026DEAu,  
    0x00002E13u,      0x00FE3D95u,      0x00FFCC2Eu,      0x000146A3u,  
    0x000032DEu,      0x00FF150Fu,      0x00FFD216u,      0x0000A582u,  
    0x000027A9u,      0x00FF8E27u,      0x00FFE00Cu,      0x00004ABDu,  
    0x0000196Au,      0x00FFD09Cu,      0x00FFEE03u,      0x00001B0Du,  
    0x00000CF5u,      0x00FFEEAEu,      0x00FFF293u,      0x004E071Du,  
    0x00B1F8E3u,      0x00000000u,      0x003FDFDDu,      0x00000000u,  
    0x00000000u,      0x00000000u,      0x00000000u,      0x00000800u,  

};

const uint32 CYCODE Droop_Filter_acu[] = 
{
    0x00001C38u,      0x00000000u,      0x00000000u,      0x00001EBDu,  
    0x00001CB9u,      0x00000102u,      0x00003B76u,      0x00001F3Eu,  
    0x00001F3Eu,      0x00003DFBu,      0x00003BF7u,      0x00000102u,  
    0x00003F7Eu,      0x00003FFFu,  
};

const uint32 CYCODE Droop_Filter_cfsm[] = 
{
    0x0105F821u,      0xC0861042u,      0x0115F867u,      0x014BF88Du,  
    0xC08E30C5u,      0x0115F8D3u,      0x014BF8F4u,      0x01886943u,  
    0x219E71C9u,      0x0125F94Au,      0x012FF96Bu,      0x20C302ECu,  
    0x0113F9A6u,      0x018D44A4u,      0x21D54D2Fu,      0x015BFA10u,  
    0x0165FA31u,      0x20F9DE52u,      0x0105F801u,      0x019C6948u,  
    0x01D344AEu,      0x00000000u,  
};

