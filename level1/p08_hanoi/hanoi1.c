
extern int bushu; 
//��n��Բ�̴�x���ӽ���y�����ƶ���z������
void move(int n,char x,char y,char z){
if(n == 1){
  printf("Բ�̱��%d����%c�ƶ���%c\n",n,x,z);
}else{
  move(n-1,x,z,y);
  printf("Բ�̱��%d����%c�ƶ���%c\n",n,x,z);
  move(n-1,y,x,z);
}
bushu++;
}
