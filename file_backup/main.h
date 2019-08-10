#ifndef __M_MAIN_H__
#define __M_MAIN_H__
#include <getopt.h>
#include <signal.h>
#include "common.h"

enum _run_type_t{
    RUN_SERVER = 1,
    RUN_CLIENT,
};

class InitParam{
    private:
        int _argc;
        char **_argv;
        int _run_type;
        int _is_daemon;
        uint32_t _addr;
        uint16_t _port;
        char *_root_dir;
        char *_str_addr;
        char *_str_port;
        char *_user_name;

        void InitSignal(){
            signal(SIGPIPE, SIG_IGN);
        }
        
        void UsagePrint(){
            printf( "Usage: "\
                    "-t 1 -i 172.17.19.145 -p 9092 -u zhang -r tmp\n"\
                    "\t-d\t\tinto debug mode\n"\
                    "\t-r\t\tlisten root dir\n"\
                    "\t-t\t\trun mode:\n"\
                    "\t\t1-server\n"\
                    "\t\t2-client\n"\
                    "\t-u\t\tlogin username\n"\
                    "\t-i\t\tserver ip\n"\
                    "\t-p\t\tserver _port\n");
            return;
        }

        bool InitOpt(){
            const char *ptr= "dt:i:p:r:u:";
            int opt, m_ind = 0;;
            while((opt = getopt(_argc, _argv, ptr)) != -1) {
                switch(opt){
                    case 'd':
                        _is_daemon = 1;
                        break;
                    case 't':
                        _run_type = atoi(optarg);
                        m_ind++;
                        break;
                    case 'i':
                        _str_addr = optarg;
                        _addr = inet_addr(optarg);
                        m_ind++;
                        break;
                    case 'p':
                        _str_port = optarg;
                        _port = htons(atoi(optarg));
                        m_ind++;
                        break;
                    case 'r':
                        _root_dir = optarg;
                        m_ind++;
                        break;
                    case 'u':
                        _user_name = optarg;
                        m_ind++;
                        break;
                    default:
                        UsagePrint();
                        return false;
                }
            }
            if (!_root_dir) {
                printf("have not listen root dir\n");
                return false;
            }
            if (!_str_port || !_str_addr) {
                printf("have not port or addr\n");
                return false;
            }
            if (_run_type == 2) {
                if (!_user_name) {
                    printf("client should have username\n");
                    return false;
                }
            }
            if (m_ind < 4) {
                UsagePrint();
                return false;
            }
            return true;
        }

        bool InitDaemon(){
            if (!_is_daemon){
                daemon(1, 0);
            }
            return true;
        }

    public:
        InitParam(int argc, char **argv)
            : _argc(argc)
            , _argv(argv)
            ,_is_daemon(0) { }

        bool Init(){
            CHECK_RET(InitOpt());
            InitSignal();
            InitDaemon();
            
            return true;
        }

        void ParamPrint(){
            if (_run_type == RUN_SERVER) {
                printf("_run_type: RUN_SERVER\n");
            }else {
                printf("_run_type: RUN_CLIENT\n");
            }
            if (_is_daemon) {
                printf("_run_mode: DEBUG\n");
            }else {
                printf("_run_mode: RELEASE\n");
            }
            printf("_root_dir: %s\n", _root_dir);
            printf("_addr: %s\n", _str_addr);
            printf("_port: %s\n", _str_port);
            printf("_user: %s\n", _user_name);
        }

        bool ModeIsServer(){
            return (_run_type == RUN_SERVER);
        }

        char *GetRootDir(){
            return _root_dir;
        }

        char *GetStrAddr(){
            return _str_addr;
        }

        char *GetStrPort(){
            return _str_port;
        }

        char *GetUserName(){
            return _user_name;
        }
};

#endif
