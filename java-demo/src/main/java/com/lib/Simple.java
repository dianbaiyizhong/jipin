package com.lib;

public class Simple {
    public native void initModule();
    public native void uninitModule();
    public native String callPython(String param);
}
