#include <stdio.h>
void main (int artgc, char **argv, char **env)
{
unsigned long v[2]; /* Plaintext */
unsigned long k[4]; /* Key */
unsigned long w[2]; /* cipher text */
/* Input to Plain Text */
v[0] = 0x12345678; v[1] = 0x90ABCDEF;
printf("\n\n\nInput Data: ");
printf (" v = 0x%x %x\n\n", v[0], v[1]);
/* Key */
k[0] = 0x11223344; k[1] = 0x55667788;
k[2] = 0x9900AABB; k[3] = 0xCCDDEEFF;
printf ("Key = 0x%x %x %x %x\n\n", k[0], k[1], k[2], k[3]);
/* Now call Encode Routine */
tea_code (v, k);
printf ("\nEncoded data = 0x%x %x\n\n", v[0], v[1]);
/* Now call Decode Routine */
tea_decode (v, k);
printf ("\nDecoded data = 0x%x %x\n", v[0], v[1]);
}
tea_code(long* v, long* k)
{
/* long is 4 bytes. */
unsigned long v0=v[0], v1=v[1];
unsigned long k0=k[0], k1=k[1], k2=k[2], k3=k[3];
unsigned long sum=0;
unsigned long delta = 0x9e3779b9, n=32 ;
while (n-- > 0) {
sum += delta ;
v0 += (v1<<4)+k0 ^ v1+sum ^ (v1>>5)+k1 ;
v1 += (v0<<4)+k2 ^ v0+sum ^ (v0>>5)+k3 ;
}
v[0]=v0 ;
v[1]=v1 ;
}
tea_decode(long* v, long* k)
{
unsigned long v0=v[0], v1=v[1];
unsigned long k0=k[0], k1=k[1], k2=k[2], k3=k[3];
unsigned long n=32, sum, delta=0x9e3779b9 ;
sum=delta<<5 ;
while (n-- > 0) {
v1 -= (v0<<4)+k2 ^ v0+sum ^ (v0>>5)+k3 ;
v0 -= (v1<<4)+k0 ^ v1+sum ^ (v1>>5)+k1 ;
sum -= delta ;
}
v[0]=v0 ;
v[1]=v1 ;
}
