# ##############################################################################
# apps/external/can_flasher/CMakeLists.txt
#
# ##############################################################################


if(CONFIG_EXTERNAL_CAN_FLASHER)
    set(CAN_FLASHER_PATH ${CMAKE_SOURCE_DIR}/../apps/external/can_flasher)
    set(CAN_FLASHER_SRC_PATH ${CAN_FLASHER_PATH}/src)

    add_subdirectory(${CAN_FLASHER_SRC_PATH})

    # Set the list of sources.
    GET_CAN_FLASHER_FILES(CAN_FLASHER)
    list(APPEND CAN_FLASHER_SRCS can_flasher.c)

    # Set the list of include directories
    GET_GET_CAN_FLASHER_INC(CAN_FLASHER)
    list(APPEND CAN_FLASHER_INC ${CAN_FLASHER_PATH})

    message("-- CONFIG_EXTERNAL_CAN_FLASHER_PROGNAME: ${CONFIG_EXTERNAL_CAN_FLASHER_PROGNAME}")
    message("-- CONFIG_EXTERNAL_CAN_FLASHER_STACKSIZE: ${CONFIG_EXTERNAL_CAN_FLASHER_STACKSIZE}")
    message("-- CONFIG_EXTERNAL_CAN_FLASHER_PRIORITY: ${CONFIG_EXTERNAL_CAN_FLASHER_PRIORITY}")

    # Build application
    nuttx_add_application(NAME ${CONFIG_EXTERNAL_CAN_FLASHER_PROGNAME}
                          SRCS ${CAN_FLASHER_SRCS}
                          INCLUDE_DIRECTORIES ${CAN_FLASHER_INC}
                          STACKSIZE ${CONFIG_EXTERNAL_CAN_FLASHER_STACKSIZE}
                          PRIORITY ${CONFIG_EXTERNAL_CAN_FLASHER_PRIORITY})

endif()
