package com.infinite.jniapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = MainActivity.class.getSimpleName();

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
    }
}
