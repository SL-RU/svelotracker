(ede-cpp-root-project "gps_test"
                      :name "gps_test"
		      :spp-table '(("__weak" . "__attribute__((weak))")
				    ("__packed" . "__attribute__((__packed__))")
				    ("USE_HAL_DRIVER" . "")
				    ("STM32F401xE" . ""))
      		      :compile-command "make"
                      :file "/mnt/doc/prj/svelotracker/src/test/gps_test/project.el"
                      :include-path '("/app"
                                      "/Controls"
                                      "/dev"
                                      "/Drivers/CMSIS/Device/ST/STM32F4xx/Include"
                                      "/Drivers/CMSIS/Include"
                                      "/Drivers/STM32F4xx_HAL_Driver/Inc"
                                      "/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy"
                                      "/gui"
                                      "/Inc"
                                      "/MakiseGUI/MakiseGUI"
                                      "/MakiseGUI/MakiseGUI/fonts"
                                      "/MakiseGUI/MakiseGUI/gui"
                                      "/MakiseGUI/MakiseGUI/gui/elements"
                                      "/MakiseGUI/MakiseGUI/gui/styles"
                                      "/MakiseGUI/MakiseGUI/ILI9340C"
                                      "/Middlewares/Third_Party/FatFs/src"
                                      "/Middlewares/Third_Party/FatFs/src/drivers"
                                      )
		      )