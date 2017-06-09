# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Inherit device configuration
$(call inherit-product, $(LOCAL_PATH)/full_ancora_tmo.mk)

PRODUCT_RELEASE_NAME := ancora_tmo

# Setup device configuration
PRODUCT_NAME := lineage_ancora_tmo
PRODUCT_DEVICE := ancora_tmo
PRODUCT_BRAND := Samsung
PRODUCT_MANUFACTURER := Samsung
PRODUCT_MODEL := SGH-T679

PRODUCT_BUILD_PROP_OVERRIDES += BUILD_FINGERPRINT=samsung/ancora_tmo/ancora_tmo:2.3.6/GINGERBREAD/XXLMJ:user/release-keys PRIVATE_BUILD_DESC="ancora_tmo-user 2.3.6 GINGERBREAD XXLMJ release-keys"
