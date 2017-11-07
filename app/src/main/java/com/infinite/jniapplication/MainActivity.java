package com.infinite.jniapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    //参考文章http://www.cnblogs.com/rocomp/p/4892866.html

    private static final String TAG = MainActivity.class.getSimpleName();

    static {
        System.loadLibrary("MzUtils");
    }

    public static native void cInvokeJava();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.btEncode).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String message = "Hello";
                Log.i(TAG, "encode : " + MzUtils.encode(message, message.length()));
            }
        });

        findViewById(R.id.btDecode).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String message = "Ifmmp";
                Log.i(TAG, "decode : " + MzUtils.decode(message, message.length()));
            }
        });

        findViewById(R.id.btCInvokeJava).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                cInvokeJava();
            }
        });

        findViewById(R.id.btPrintAndroidLog).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
               // MzUtils.printAndroidLog();
            }
        });
    }

    public void showToast(String message) {
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show();
    }
}
