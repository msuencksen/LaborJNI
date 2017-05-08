package com.hsfl.mobilecpp1;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // store handle to our TextView
        tv = (TextView) findViewById(R.id.sample_text);

        tv.setText("Welcome from Java");

        // call JNI
        // appendWelcomeFromJNI(); // use either this
        welcomeFromJNI(); // or this line, not both
    }

    // platform-independent get method
    public String getWelcomeText()
    {
        return (String) tv.getText();
    }

    // platform-independent set method
    public void setWelcomeText(String newText)
    {
        if (newText!=null) {
            tv.setText(newText);
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

    public native void welcomeFromJNI();
    public native void appendWelcomeFromJNI();
}
