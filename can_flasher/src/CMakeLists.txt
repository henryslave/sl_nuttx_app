# ##############################################################################
# apps/external/can_flasher/src/CMakeLists.txt
#
# ##############################################################################


function(GET_CAN_FLASHER_FILES DST)

    set(OUT_FILES
        ${CAN_FLASHER_SRC_PATH}/can.c
    )

    set(${DST}_SRCS ${OUT_FILES} PARENT_SCOPE)

endfunction()


function(GET_CAN_FLASHER_INC DST)
    set(OUT_INC
        ${CAN_FLASHER_SRC_PATH}/
    )

    set(${DST}_INC ${OUT_INC} PARENT_SCOPE)

endfunction()


function(GET_CAN_FLASHER_DEF DST)

    set(OUT_DEF
        LIB_DUMMY_1
        LIB_DUMMY_2=20
    )

    set(${DST}_DEF ${OUT_DEF} PARENT_SCOPE)

endfunction()


function(GET_ILLD_COMPILER_OPTION MCPU DST)

    set(${DST}_COMPILER_OPTION

        -Wno-implicit-function-declaration
        -Wno-sign-compare
        -Wextra
        -Wall
        -Wdiv-by-zero
        -Warray-bounds
        -Wignored-qualifiers
        -Wformat
        -Wformat-security
        -pipe
        -fno-short-enums
        -fshort-double
        -mcpu=${MCPU}
        -mversion-info
    
    PARENT_SCOPE)

endfunction()


function(GET_ILLD_LINKER_OPTION DST)

    set(${DST}_LINKER_OPTION
        $<$<CONFIG:Release>:-s>    
    PARENT_SCOPE)

endfunction()


if ( LIB_TYPE STREQUAL "illd" )
    message("-- INFO: Building tricore-hal using iLLD.")
endif()
