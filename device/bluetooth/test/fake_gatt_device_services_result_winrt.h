// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_BLUETOOTH_TEST_FAKE_GATT_DEVICE_SERVICES_RESULT_WINRT_H_
#define DEVICE_BLUETOOTH_TEST_FAKE_GATT_DEVICE_SERVICES_RESULT_WINRT_H_

#include <windows.devices.bluetooth.genericattributeprofile.h>
#include <windows.foundation.collections.h>
#include <windows.foundation.h>
#include <wrl/client.h>
#include <wrl/implements.h>

#include <stdint.h>

#include <string>
#include <vector>

#include "base/macros.h"

namespace device {

class FakeGattDeviceServicesResultWinrt
    : public Microsoft::WRL::RuntimeClass<
          Microsoft::WRL::RuntimeClassFlags<
              Microsoft::WRL::WinRt | Microsoft::WRL::InhibitRoOriginateError>,
          ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::
              IGattDeviceServicesResult> {
 public:
  explicit FakeGattDeviceServicesResultWinrt(
      ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::
          GattCommunicationStatus status);
  FakeGattDeviceServicesResultWinrt(
      ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::
          GattCommunicationStatus status,
      const std::vector<std::string>& uuids);
  ~FakeGattDeviceServicesResultWinrt() override;

  // IGattDeviceServicesResult:
  IFACEMETHODIMP get_Status(
      ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::
          GattCommunicationStatus* value) override;
  IFACEMETHODIMP get_ProtocolError(
      ABI::Windows::Foundation::IReference<uint8_t>** value) override;
  IFACEMETHODIMP get_Services(
      ABI::Windows::Foundation::Collections::IVectorView<
          ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::
              GattDeviceService*>** value) override;

 private:
  ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::
      GattCommunicationStatus status_;
  std::vector<
      Microsoft::WRL::ComPtr<ABI::Windows::Devices::Bluetooth::
                                 GenericAttributeProfile::IGattDeviceService>>
      services_;

  DISALLOW_COPY_AND_ASSIGN(FakeGattDeviceServicesResultWinrt);
};

}  // namespace device

#endif  // DEVICE_BLUETOOTH_TEST_FAKE_GATT_DEVICE_SERVICES_RESULT_WINRT_H_
