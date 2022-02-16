
int main(){
    char P0;

    // clear 
    P0  = 0x95;
    P0 &= 0xEF;
    P0 &= ~(0x10);

    // set
    P0  = 0x83;
    P0 |= 0x08;

	while(1);
}
