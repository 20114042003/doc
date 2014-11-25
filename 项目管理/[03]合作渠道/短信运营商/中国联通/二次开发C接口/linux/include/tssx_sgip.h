#if !defined ZTE_SGIP_INTERFACE_H_20070810_
#define ZTE_SGIP_INTERFACE_H_20070810_

#define ERROR_OK			           0
#define ERROR_SOCKET_CREATE  	-100
#define ERROR_CONNECT		      -101
#define ERROR_SOCKET_WRITE	  -102
#define ERROR_SOCKET_READ	    -103
#define ERROR_ICP_ID		      -104
#define ERROR_AUTH		        -105
#define ERROR_MSG_LEN		      -106
#define ERROR_FEE_CODE		    -107
#define ERROR_SERVICE_ID	    -108
#define ERROR_FLOW_CONTROL	  -109
#define ERROR_SOCKET_CLOSE	  -110
#define ERROR_CMD			        -111
#define ERROR_INTERNAL		    -200
#define ERROR_UNKNOWN		      -201
#define ERROR_ARGUMENT		    -202

/***********************************************************************************\                        
*DESCRIPTION:   DLL�ĵ�����������������DLL�Ľӿں���            	                *
*INPUT:			                                                                    *
*OUTPUT:		                    				                                *
*AUTHOR/DATE:   ���/2007.08.10			                    						*
*NOTE:                                                                              *
************************************************************************************/
//A.  ����Դ�ڵ����
void set_src_node(int num);
                    
//B .  �����ؽ�������
int SGIP_Connect(char *gw_ip,short port,char *username,char *passwd);

//C .  �������ύ��Ϣ
int SGIP_Submit(int conn_id,			//the return value by SGIP_Connect		
	char *sp_dial_num,		               //SP�����
	char *ICPID,			                   //��ҵ����
	char *service_id,			               //ҵ�����
	unsigned char fee_type,			         //01=��� 02=���� 03=���� 04=�ⶥ 05=SP�շ�
	char *fee_value,			               //�ʷѴ��룬�Է�Ϊ��λ
	char *give_value,			               //���ͷ��ô��룬�Է�Ϊ��λ
	unsigned char agent_flag,			       //���շѱ�־��0��Ӧ�գ�1��ʵ��
	unsigned char mt_flag,			         //����MT��Ϣ��ԭ��
						                           //	0-MO�㲥����ĵ�һ��MT��Ϣ��
						                           //	1-MO�㲥����ķǵ�һ��MT��Ϣ��
						                           //	2-��MO�㲥�����MT��Ϣ��
	unsigned char priority,		           //���ȼ�0-9�ӵ͵���
	char *valid_time,			               //���ʱ�䣬��ʽΪYYYYMMDDHHMISS
	char *at_time,			                 //���ʱ�䣬��ʽΪYYYYMMDDHHMISS
	unsigned char report_flag,	         //״̬������
						                           //	0-������Ϣֻ��������ʱҪ����״̬����
						                           //	1-������Ϣ��������Ƿ�ɹ���Ҫ����״̬����
						                           //	2-������Ϣ����Ҫ����״̬����
	unsigned char tp_pid,			           //һ����0 ����ֵ�μ�GSM03.40
	unsigned char tp_udhi,			         //һ����0 ����ֵ�μ�GSM03.40
	unsigned char msg_type,		           //��Ϣ����
	unsigned char msg_format,	           //��Ϣ��ʽ 0=ASCII 4=bin 8=UCS2 15=GB
	char *charge_mobile,		             //���Ѻ��룬���Ϊ�գ����������Ϣ�����ķ�����UserNumber������û�֧��
 	unsigned char user_num,		           //�����ֻ����� <100
	char *dest_mobiles,		               //�����ֻ����룬�Կո�ָ�
	char *msg,				                   //��Ϣ����
	unsigned long  msg_len,		           //��Ϣ����
	unsigned long *p_seq1,		           //�������ɵ����к�1-3�����Դ���NULL
	unsigned long *p_seq2,
	unsigned long *p_seq3
	);


//D .  ���������ضϿ�����
int SGIP_Disconnect(int conn_id);

//E . �ȴ������� MO ��Ϣ  
int SGIP_Get_MO(int sockfd,void **pp_MO);

//MO��Ϣ�ṹ����

struct MO_msg{
        char             sourceUser[21]; //������Ϣ���ֻ�
        char             SPNumber[21];	 //SP�����
        unsigned char    tp_pid;
        unsigned char    tp_udhi;
        unsigned char    msgFormat;		   //��Ϣ��ʽ
        unsigned long    msgLen;		     //��Ϣ����
        char             msg[160];			 //��Ϣ����
};     
//Report��Ϣ�ṹ����
struct MO_report{
 	unsigned long	         seq1;					 //��Ӧ��submit���к�1-3
	unsigned long	         seq2;
	unsigned long	         seq3;
	unsigned char	         report_type;    //״̬��������
	char			             mobile[21];		 //Ŀ���ֻ���
	unsigned char	         state;				   //״̬ 0�����ͳɹ� 1���ȴ����� 2������ʧ��
	unsigned char	         errCode;				 //�������
};
//SGIP_Get_MO ʱ�õ�����Ϣ
#define MO_MSG 	  1
#define MO_REPORT 2

#endif

