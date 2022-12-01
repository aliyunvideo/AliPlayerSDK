export targetVersion=$1


if [ ! "${targetVersion}" ] 
    then
    echo "缺少要删除的pod版本号"
    exit
fi

pod trunk delete AliPlayerPartSDK_iOS ${targetVersion}
pod trunk delete AliPlayerSDK_iOS ${targetVersion}
pod trunk delete AliPlayerSDK_iOS_ARTC ${targetVersion}
pod trunk delete AliPlayerSDK_iOS_MPF_FILTER ${targetVersion}
pod trunk delete AliPlayerSDK_iOS_VFI_FILTER ${targetVersion}
pod trunk delete AliPlayerSDK_iOS_AEM_FILTER ${targetVersion}