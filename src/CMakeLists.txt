set(kerm_SRCS
   task.cpp
   actions.cpp
   common.cpp
   formAddService.cpp
   formProcessRunner.cpp
   formRemoveService.cpp
   formSrvProp.cpp
   formSwitchToRunlevel.cpp
   kermmainwin.cpp
   servicefile.cpp
   main.cpp
 )

kde4_add_executable(kerm ${kerm_SRCS})

target_link_libraries(kerm ${KDE4_KDEUI_LIBS} ${KDE4_KIO_LIBS})

install(TARGETS kerm ${INSTALL_TARGETS_DEFAULT_ARGS} )


########### install files ###############

install( FILES kerm.desktop  DESTINATION ${XDG_APPS_INSTALL_DIR} )
install( FILES kerm.kcfg  DESTINATION  ${KCFG_INSTALL_DIR} )
install( FILES kermui.rc  DESTINATION  ${DATA_INSTALL_DIR}/kerm )
