(ede-cpp-root-project "gps_test"
                      :name "gps_test"
		      :spp-table '(("__weak" . "__attribute__((weak))")
				    ("__packed" . "__attribute__((__packed__))")
				    ("USE_HAL_DRIVER" . "")
				    ("STM32F401xE" . ""))
      		      :compile-command "make"
                      :file "/home/lyra/prj/svelotracker/src/test/gps_test/project.el"
                      :include-path '("/Drivers/STM32F4xx_HAL_Driver/Inc"
                                      "/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy"
                                      "/Drivers/CMSIS/Include"
                                      "/Drivers/CMSIS/Device/ST/STM32F4xx/Include"
                                      "/MakiseGUI/MakiseGUI"
                                      "/MakiseGUI/MakiseGUI/ILI9340C"
                                      "/MakiseGUI/MakiseGUI/fonts"
                                      "/MakiseGUI/MakiseGUI/gui"
                                      "/MakiseGUI/MakiseGUI/gui/elements"
                                      "/MakiseGUI/MakiseGUI/gui/styles"
                                      "/Inc"
                                      "/dev"
                                      "/app"
                                      "/Controls"
                                      "/Middlewares/Third_Party/FatFs/src"
                                      "/Middlewares/Third_Party/FatFs/src/drivers"
                                      "/gui"
                                      )
		      )