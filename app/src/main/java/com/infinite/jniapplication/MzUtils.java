package com.infinite.jniapplication;

/**
 * Created by Administrator on 11/7/2017.
 */

public class MzUtils {
    static {
        System.loadLibrary("MzUtils");
    }

    public static native String decode(String message, int length);

    public static native String encode(String message, int length);
}
