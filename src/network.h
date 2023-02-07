#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "account_manager.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MSG_SIZE 2048

//* Tín hiệu điều khiển
// chung

// server
#define REGISTER_SUCC 100
#define ACC_EXISTED -10
#define ACTIVATE_SUCC 101
#define ACTIVATE_FAIL -11
#define LOGIN_SUCC 102
#define INCORRECT_ACC -12
#define SIGNED_IN_ACC 103
#define RECV_SUCC 104
#define ACC_BLOCKED 0
#define ACC_IDLE 2
#define ACC_ACTIVATED 1
#define CHANGE_PASSWORD_SUCC 8
#define CHANGE_PASSWORD_FAIL -8
#define WRONG_PASSWORD -10
#define CORRECT_PASSWORD 10

// client
#define REGISTER_REQ 200
#define ACTIVATE_REQ 201
#define LOGIN_REQ 202
#define SEARCH_REQ 203
#define CHANGE_PASS_REQ 204
#define QUIT_REQ 205

#define MSG_SENT_SUCC 302
#define END_CHAT 312

#define SHOW_USER 401
#define PRIVATE_CHAT 402
#define CHAT_ALL 403

#define GROUP_CHAT_INIT 405
#define SHOW_GROUP 406
#define NEW_GROUP 407
#define MSG_MAKE_GROUP_SUCC 408
#define MSG_MAKE_GROUP_ERR 409
#define JOIN_GROUP 410
#define JOIN_GROUP_SUCC 411
#define HANDLE_GROUP_MESS 412
#define INVITE_FRIEND 413
#define INVITE_FRIEND_SUCC 414
#define GROUP_CHAT 415
#define GROUP_INFO 416
#define SHOW_GROUP_NAME 417
#define SHOW_GROUP_MEM 418
#define LEAVE_GROUP 419
#define LEAVE_GROUP_SUCC 420

#define SEARCH_USERS 422
#define CHANGE_PASSWORD 423
#define LOG_OUT 424

//* Cấu trúc gói tin
typedef struct Package_
{
    char msg[MSG_SIZE];           /* nội dung thông điệp */
    char sender[USERNAME_SIZE];   /* username người gửi */
    char receiver[USERNAME_SIZE]; /* username người nhận */
    int group_id;                 /*id group muốn gửi*/
    int ctrl_signal;              /* mã lệnh */
} Package;

#endif