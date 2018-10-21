#include <stdio.h>
#include <pcap.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#define MAXBYTES2CAPTURE 2048

void dumpcode(const u_char *, int);
void processPacket(u_char *,const struct pcap_pkthdr *,const u_char *);



struct IpHeader{
    u_char VL;
    u_char TOS;
    u_short totalLength;
    u_short identification;
    u_short FlagFragment;
    u_char TTL;
    u_char Protocol;
    u_short Checksum;
    struct in_addr ip_src, ip_dst;
};

struct Ether{
    u_char da[6];
    u_char sa[6];
    u_short type;
};

int main(int argc, char const *argv[])
{
    int ret = 0;
    int count = 0;
    pcap_t *descr = NULL;
    struct pcap_pkthdr *header;
    char errBuf[PCAP_ERRBUF_SIZE], *device = NULL;
    memset(errBuf,0,PCAP_ERRBUF_SIZE);
    const u_char *packet;

    struct bpf_program filter;
    bpf_u_int32 mask =0;

    device = pcap_lookupdev(errBuf);

    printf("Opening device %s\n",device);
    descr = pcap_open_live(device, MAXBYTES2CAPTURE,1,512,errBuf);
    
    if(pcap_compile(descr,&filter,"arp",1,mask)==-1){
            printf("%s\n",pcap_geterr(descr));
            exit(EXIT_FAILURE);
    }
    if(pcap_setfilter(descr,&filter)==-1){
            printf("%s\n",pcap_geterr(descr));
            exit(EXIT_FAILURE);
    }

    while((ret = pcap_next_ex(descr, &header, &packet)) >= 0){
        if (ret == 0) {
            continue;
        }
        
        processPacket((u_char*)&count,header,packet);
    }
    
    pcap_close(descr);
    return 0;
}
void processPacket(u_char *arg, const struct pcap_pkthdr *pkthdr, const u_char *packet){
    int *coutner = (int*)arg;
    int i = 0;
    char sip[20];
    char dip[20];

    printf("-------------------------\nPacker Count : %d\n",++(*coutner));
    printf("Received Packet Size : %d\n",pkthdr->len);
    printf("Payload: \n\n");

    struct Ether* einfo = (struct Ether*)packet;
    struct IpHeader* addrInfo = (struct IpHeader*)(packet + 14);
    if(ntohs(einfo->type) == 0x0800){
        inet_ntop(AF_INET,&(addrInfo->ip_src),sip,sizeof(sip));
        inet_ntop(AF_INET,&(addrInfo->ip_dst),dip,sizeof(dip));

        printf("%s\n",sip);
        printf("%s\n",dip);
    }
    printf("DA");
    
    for(i = 0;i<6;i++){
        printf(": %02x",einfo->da[i]);
    }
    
    printf("\n");

    printf("SA");
    for(i = 0;i<6;i++){
        printf(": %02x",einfo->sa[i]);
    }
    printf("\n");

    printf("TYPE :");
    printf("0x%04x", ntohs(einfo->type));

    printf("\n");

    dumpcode(packet,pkthdr->len);

    return;
}

void dumpcode(const u_char *buf, int len){
    int i;

    printf("%7s", "offset ");
    for(i=0; i<16;i++){
        printf("%02x ", i);

        if(!(i % 16 -7))
            printf("- ");
    }
    printf("\n\r");

    for(i=0; i<len; i++){
        if(!(i%16))
            printf("0x%04x ", i);

        printf("%02x ", buf[i]);

        if(!(i % 16 - 7))
            printf("- ");

        if(!(i % 16 - 15)){
            putchar(' ');
            printf("\n\r");
        }
    }

    printf("\n\r");
}







