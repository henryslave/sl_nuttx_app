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


function(GET_GET_CAN_FLASHER_INC DST)
    set(OUT_INC
        ${CAN_FLASHER_SRC_PATH}/
    )

    set(${DST}_INC ${OUT_INC} PARENT_SCOPE)

endfunction()


function(GET_ILLD_DEF CPU BOOT DST)

    if( ${CPU} STREQUAL "tc367" )
        SET(CPU_DEF
            PXLLD_CORE_NR=2
            UC_PLL0_INCLK_MAX=40
            UC_PLL1_INCLK_MAX=40
            )
    elseif ( ${CPU} STREQUAL "tc387")
        SET(CPU_DEF 
            PXLLD_CORE_NR=4
            UC_PLL0_INCLK_MAX=24
            UC_PLL1_INCLK_MAX=24
            )
    else()
        MESSAGE(FATAL_ERROR "Architecture ${CPU} not supported.")
    endif()

    set(COMMON_DEF
        LIB_AURIX_ILLD
        BOARD_XTAL_CLOCK=20
        UC_PLL0_CLOCK=300
        UC_PLL1_CLOCK=320
        UC_PLL2_CLOCK=200
        UC_BACKUP_CLOCK=100
        UC_SRI_CLOCK=300
        UC_SPB_CLOCK=100
        UC_FSI_CLOCK=100
        UC_FSI2_CLOCK=300
        UC_QSPI_CLOCK=200
        UC_STM_CLOCK=100
        UC_PLL0_VCO_MIN=400
        UC_PLL0_VCO_MAX=800
        UC_PLL0_VCO_REC=600
        UC_PLL1_VCO_MIN=400
        UC_PLL1_VCO_MAX=800
        UC_PLL1_VCO_REC=640
        UC_PLL1_DIBBY=0
        UC_PFLASH_PF=30
        UC_PFLASH_PFECC=10
        UC_DFLASH_DF=100
        UC_DFLASH_DFECC=20
        SCU_CCUCON1_QSPI_CLKSEL=2
    )

    set(OUT_DEF ${COMMON_DEF} ${CPU_DEF})

    if (${BOOT})
        list(APPEND OUT_DEF PXLLD_BOOT)
    endif()            

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
