#!/usr/bin/env bash

newPackageDir=$1

CURRENT_DIR=$(cd $(dirname $0); pwd)
echo ${CURRENT_DIR}

rm -rf alivcffmpeg.framework/
rm -rf AliyunMediaDownloader.framework/
rm -rf AliyunPlayer.framework/
rm -rf artcSource.framework/
rm -rf mpf_filter.framework/
rm -rf vfi_filter.framework/
rm -rf aem_filter.framework/

echo "delete complete"

cp -r ${newPackageDir}/SDK/ARM_SIMULATOR/alivcffmpeg.framework/ ${CURRENT_DIR}/
cp -r ${newPackageDir}/SDK/ARM_SIMULATOR/AliyunMediaDownloader.framework/ ${CURRENT_DIR}/
cp -r ${newPackageDir}/SDK/ARM_SIMULATOR/AliyunPlayer.framework/ ${CURRENT_DIR}/
cp -r ${newPackageDir}/SDK/ARM_SIMULATOR/artcSource.framework/ ${CURRENT_DIR}/
cp -r ${newPackageDir}/SDK/ARM_SIMULATOR/mpf_filter.framework/ ${CURRENT_DIR}/
cp -r ${newPackageDir}/SDK/ARM_SIMULATOR/vfi_filter.framework/ ${CURRENT_DIR}/
cp -r ${newPackageDir}/SDK/ARM_SIMULATOR/aem_filter.framework/ ${CURRENT_DIR}/

