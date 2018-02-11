#include <system.h>

void detectDevices(){
	unsigned long i = 0;
	for(unsigned char busses = 0 ; busses < 250 ; busses++){
		for(unsigned char slots = 0 ; slots < 32 ; slots++){
			for(unsigned char functions = 0 ; functions < 8 ; functions++){
				unsigned short vendorID = pciConfigReadWord(busses,slots,functions,0);
				if(vendorID!=0xFFFF){
					unsigned long classID = (pciConfigReadWord(busses,slots,functions,0x0A) & ~0x00FF) >> 8;
					unsigned long suclassID = (pciConfigReadWord(busses,slots,functions,0x0A) & ~0xFF00);// >> 8;
					if(classID==0x01){
						if(suclassID==0x01){
							// ATA OPSLAG
						}else if(suclassID==0x02){
							// FLOPPY OPSLAG
						}else{
							// UNKNOWN
						}
					}
					i = i + 1;
				}
			}
		}
	}
	printf(" | PCI count: %x",i);
}

unsigned long pciConfigReadWord (unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset){
    unsigned long address;
    unsigned long lbus  = (unsigned long)bus;
    unsigned long lslot = (unsigned long)slot;
    unsigned long lfunc = (unsigned long)func;
    unsigned short tmp = 0;
 
    /* create configuration address as per Figure 1 */
    address = (unsigned long)((lbus << 16) | (lslot << 11) |
              (lfunc << 8) | (offset & 0xfc) | ((unsigned long)0x80000000));
 
    /* write out the address */
    outportl (0xCF8, address);
    /* read in the data */
    /* (offset & 2) * 8) = 0 will choose the first word of the 32 bits register */
    tmp = (unsigned long)((inportl (0xCFC) >> ((offset & 2) * 8)) & 0xffff);
    return (tmp);
 }
