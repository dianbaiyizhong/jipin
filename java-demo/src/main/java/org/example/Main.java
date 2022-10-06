package org.example;

import com.lib.Simple;

public class Main {
    public static void main(String[] args) {
        System.load("/usr/local/Simple.cpython-37m-x86_64-linux-gnu.so");
        Simple simple = new Simple();
        simple.initModule();
        String result = simple.callPython("this is called from java");
        simple.uninitModule();
        System.out.println(result);
    }
}