#include <stdio.h>
#include <string.h>
int main() {
    char pms[4];
    char change_pms[100][3];
    int i;
    i = 0;
    int j;
    //int num = 0;
    int a;//�ļ�������Ȩ��ֵ
    a = 0;
    int b;
    b = 0;
    int c;
    c = 0;
    int count = 0;
    //���뵱ǰ�ļ�Ȩ��
    scanf("%s\n", pms);
    //printf("%s", pms);
    //������ӻ���ɾ�����ļ�Ȩ��
    while (scanf("%s",change_pms[i++]) != EOF) {
		count ++;
    }
    //�ж�ԭ�ļ���Ȩ�ޣ���ʮ���Ʊ�ʾ
    for (i = 0; i < strlen(pms); i++) {
        if (pms[i] == 'r') {
            a += 4;
        }
		if (pms[i] == 'w') {
            a += 2;
        }
		if (pms[i] == 'x') {
            a += 1;
        } 
    }
    //printf("%d", a);
    
    for (i = 0; i < count; i++) {
        j = 0;
        if (change_pms[i][j] == '+' ) {
            if (change_pms[i][j + 1] == 'r') 
           {
               b += 4;   
            }
		   	else if (change_pms[i][j + 1] == 'w'  ) 
           {
                b += 2;
            } 
			else if (change_pms[i][j + 1] == 'x' )  
           {
                b += 1;
            }
		}
		else if (change_pms[i][j] == '-' ) {
            if (change_pms[i][j + 1] == 'r' ) 
           {
               b -= 4;   
            } else if (change_pms[i][j + 1] == 'w' ) 
           {
                b -= 2;
            } else if (change_pms[i][j + 1] == 'x' )
           {
                b -= 1;
            }
        }
		

		}

    /*for (i = 0; i < 4; i++) {
            printf("%c-%c\n",change_pms[i][0], change_pms[i][1]);
    }*/
    //printf("%d\n", strlen(change_pms[0]);
    //printf("%d\n", b);
    //printf("%d\n", c);
    printf("%d", a + b);
    return 0;
}
