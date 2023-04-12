#include <string.h>
#include "srcp.h"

typedef struct {
   int ErrorCode;
   char *AnswerTemplate;
} AnswerStruct;

static AnswerStruct AnswerCommandTable[] = {
   { SRCP_ERRNO_ANTWORT_COMMAND_OK, SRCP_STR_ANTWORT_COMMAND_OK },
   { SRCP_ERRNO_ANTWORT_COMMAND_UNKNOWN_ERR, SRCP_STR_ANTWORT_COMMAND_UNKNOWN_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_UNVAL_ERR, SRCP_STR_ANTWORT_COMMAND_UNVAL_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_WRVAL_ERR, SRCP_STR_ANTWORT_COMMAND_WRVAL_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_DEVLOCK, SRCP_STR_ANTWORT_COMMAND_DEVLOCK },
   { SRCP_ERRNO_ANTWORT_COMMAND_FORBID_ERR, SRCP_STR_ANTWORT_COMMAND_FORBID_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_NODATA_ERR, SRCP_STR_ANTWORT_COMMAND_NODATA_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_TIMEOUT, SRCP_STR_ANTWORT_COMMAND_TIMEOUT },
   { SRCP_ERRNO_ANTWORT_COMMAND_TOLONG_ERR, SRCP_STR_ANTWORT_COMMAND_TOLONG_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_TOSHORT_ERR, SRCP_STR_ANTWORT_COMMAND_TOSHORT_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_UNPROT_ERR, SRCP_STR_ANTWORT_COMMAND_UNPROT_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_UNDEV_ERR, SRCP_STR_ANTWORT_COMMAND_UNDEV_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_UNGRP_ERR, SRCP_STR_ANTWORT_COMMAND_UNGRP_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_UNOP_ERR, SRCP_STR_ANTWORT_COMMAND_UNOP_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_REINIT_ERR, SRCP_STR_ANTWORT_COMMAND_REINIT_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_UNSUPP_ERR, SRCP_STR_ANTWORT_COMMAND_UNSUPP_ERR },
   { SRCP_ERRNO_ANTWORT_COMMAND_ERR, SRCP_STR_ANTWORT_COMMAND_ERR },
};


int SrcpEncAnswerCommand(char *Buf, int Answer)
{
   return(strlen(strcpy(Buf, AnswerCommandTable[Answer].AnswerTemplate))+1);
}
