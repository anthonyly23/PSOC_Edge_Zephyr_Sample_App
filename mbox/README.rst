.. _infineon-mbox-sample:

MBOX Interface
##############

Overview
********

This sample demonstrates how to use the :ref:`MBOX API <mbox_api>`.

Building and Running
********************

The sample can be built and executed on boards supporting MBOX.

This application can be built and executed one the kit_pse84_eval as follows.
Note the optional useof the -d west argument to specify a build directory,
useful when building for two different cores.

.. code-block::

   west build -b kit_pse84_eval/pse846gps2dbzc4a/m55 samples\boards\infineon\mbox -d build_cm55
   west flash -d build_cm55

   west build -b kit_pse84_eval/pse846gps2dbzc4a/m33 samples\boards\infineon\mbox -d build_cm33
   west flash -d build_cm33

**Note:** If CM55 does not have a valid application before downloading this application to CM33, there may be errors after download (due to CM33 trying to execute an invalid application)

Open a serial terminal (minicom, putty, etc.) and connect the board with the
following settings:

- Speed: 115200
- Data: 8 bits
- Parity: None
- Stop bits: 1

Reset the board and the following message will appear on the corresponding
serial port, one is the application (APP) core another is the network (NET)
core:

.. code-block:: console

   ****************** PSOC Edge MCU: CM33 Secure App start ******************

   CM33 NS image address 0x60340400, ns_stack 0x240c20c8, handler 0x6034197d
   *** Booting Zephyr OS build ES10-CR.E0.RC1 ***
   Enabling CM55
   *** Booting Zephyr OS build ES10-CR.E0.RC1 ***
   Hello from APP [core A]
   Ping [core A] (on channel 1)
   Hello from APP [core B]
   Ping [core B] (on channel 0)
   Pong [core A] (on channel 0 [data 1, 4])
   Ping [core A] (on channel 1)
   Pong [core B] (on channel 1 [data 2, 4])
   Ping [core B] (on channel 0)
   Pong [core A] (on channel 0 [data 2, 4])
   Ping [core A] (on channel 1)
   Pong [core B] (on channel 1 [data 3, 4])
   Ping [core B] (on channel 0)
   Pong [core A] (on channel 0 [data 3, 4])
   Ping [core A] (on channel 1)
   Pong [core B] (on channel 1 [data 4, 4])
   Ping [core B] (on channel 0)
   Pong [core A] (on channel 0 [data 4, 4])
