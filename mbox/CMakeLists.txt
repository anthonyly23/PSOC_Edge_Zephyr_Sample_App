# Copyright (c) 2025 Infineon Technologies AG,
# or an affiliate of Infineon Technologies AG.
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

message(STATUS "${BOARD} compile as Main in this sample")

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(mbox_ipc)

enable_language(C ASM)

target_sources(app PRIVATE src/main.c)
