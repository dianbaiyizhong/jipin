package org.example;

import com.lib.Simple;

public class Main {
    public static void main(String[] args) {
        System.load("C:\\Users\\Administrator\\Documents\\GitHub\\jipin\\cython-demo\\Simple.cp310-win_amd64.pyd");
        Simple simple = new Simple();
        simple.initModule();
        String result = simple.callPython("this is called from java");
        simple.uninitModule();
        System.out.println(result);
    }
}