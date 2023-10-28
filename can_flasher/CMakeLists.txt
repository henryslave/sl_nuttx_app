##
# @file apps/external/can_flasher/CMakeLists.txt
#

if(CONFIG_EXTERNAL_CAN_FLASHER)
  nuttx_add_application(
    NAME
    ${EXTERNAL_CAN_FLASHER_PROGNAME}
    SRCS
    can_flasher.c
    STACKSIZE
    ${EXTERNAL_CAN_FLASHER_STACKSIZE}
    PRIORITY
    ${EXTERNAL_CAN_FLASHER_PRIORITY})
endif()
