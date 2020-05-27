using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace ASTRA_Console_GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            getAvailablePorts();
            groupBox3.Enabled = false;
            groupBox4.Enabled = false;
            groupBox5.Enabled = false;
            groupBox6.Enabled = false;
            pictureBox1.Visible = false;
            pictureBox2.Visible = false;

        }
        void getAvailablePorts()
        {
            string[] ports = SerialPort.GetPortNames();
            comboBox1.Items.AddRange(ports);
        }

    

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                if(comboBox1.Text==""||comboBox2.Text=="")
                {
                    textBox2.Text = "Select port address settings";
                }
                else
                {
                    serialPort1.PortName = comboBox1.Text;
                    serialPort1.BaudRate = Convert.ToInt32(comboBox2.Text);
                    serialPort1.Open();
                    progressBar1.Value = 100;
                    //button1.Enabled = true;
                    button2.Enabled = true;
                    //textBox1.Enabled = true;
                    button3.Enabled = false;
                    button4.Enabled = true;
                    groupBox3.Enabled = true;
                    groupBox4.Enabled=true;
                    groupBox5.Enabled = true;
                    groupBox6.Enabled = true;
                    pictureBox1.Visible = true;
                    pictureBox2.Visible = true;

                }
            }
            catch(UnauthorizedAccessException)
            {
                textBox2.Text = "Unauthorized Access";
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
            progressBar1.Value = 0;
            //button1.Enabled = false;
            button2.Enabled = false;
            button4.Enabled = false;
            button3.Enabled = true;
            //textBox1.Enabled = false;
            groupBox3.Enabled = false;
            groupBox4.Enabled = false;
            groupBox5.Enabled = false;
            groupBox6.Enabled = false;
            pictureBox1.Visible = false;
            pictureBox2.Visible = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //serialPort1.WriteLine(textBox1.Text);
            textBox2.AppendText("REQ : validating");
            textBox2.AppendText(Environment.NewLine);
            try
            {
               // if (textBox1.Text == "")
                {
                    textBox2.AppendText("Error : NullException revoked");
                    textBox2.AppendText(Environment.NewLine);
                }
               // else
                {
                    textBox2.AppendText(serialPort1.ReadLine());
                    textBox2.AppendText(Environment.NewLine);
                }
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
            catch (ObjectDisposedException)
            {
                textBox2.AppendText("Error : NullException revoked");
                textBox2.AppendText(Environment.NewLine);
            }
            //textBox1.Text = "";


        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                textBox2.Text = "";
            }
            catch(TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            serialPort1.Write("w"); // forward ugv
            textBox2.AppendText("REQ >> code forward transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }

        }

        private void button6_Click(object sender, EventArgs e)
        {
            serialPort1.Write("a"); // left ugv
            textBox2.AppendText("REQ >> code left transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            serialPort1.Write("s");  // backward ugv
            textBox2.AppendText("REQ >> code backward transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            serialPort1.Write("d");  // right ugv
            textBox2.AppendText("REQ >> code right transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            serialPort1.Write("5"); //arm open
            textBox2.AppendText("REQ >> code arm open transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button10_Click(object sender, EventArgs e)
        {
            serialPort1.Write("0");  //arm close
            textBox2.AppendText("REQ >> code arm close transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button11_Click(object sender, EventArgs e)
        {
            serialPort1.Write("8"); //palm up
            textBox2.AppendText("REQ >> code palm up transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button12_Click(object sender, EventArgs e)
        {
            serialPort1.Write("2"); // palm down
            textBox2.AppendText("REQ >> code palm down transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button13_Click(object sender, EventArgs e)
        {
            serialPort1.Write("4"); // wrist x
            textBox2.AppendText("REQ >> code wrist x transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button14_Click(object sender, EventArgs e)
        {
            serialPort1.Write("6"); // wrist y
            textBox2.AppendText("REQ >> code wrist y transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button15_Click(object sender, EventArgs e)
        {
            serialPort1.Write("+");  // docking
            textBox2.AppendText("REQ >> code docking transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button16_Click(object sender, EventArgs e)
        {
            serialPort1.Write("-");  // undocking
            textBox2.AppendText("REQ >> code undocking transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button17_Click(object sender, EventArgs e)
        {
            serialPort1.Write("n"); //backlight 
            textBox2.AppendText("REQ >> code backlight transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button18_Click(object sender, EventArgs e)
        {
            serialPort1.Write("m");  //exhaust
            textBox2.AppendText("REQ >> code exhaust transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button26_Click(object sender, EventArgs e)
        {
            serialPort1.Write("x"); // emergency stop ugv
            textBox2.AppendText("REQ >> code emergency stop transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button19_Click(object sender, EventArgs e)
        {
            serialPort1.Write("i");  //child forward
            textBox2.AppendText("REQ >> code forward transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button20_Click(object sender, EventArgs e)
        {
            serialPort1.Write("j");  // child left
            textBox2.AppendText("REQ >> code left transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button21_Click(object sender, EventArgs e)
        {
            serialPort1.Write("l"); //child right
            textBox2.AppendText("REQ >> code right transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button22_Click(object sender, EventArgs e)
        {
            serialPort1.Write("k"); //child back
            textBox2.AppendText("REQ >> code reverse transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button23_Click(object sender, EventArgs e)
        {
            serialPort1.Write("f");  // self destruct child
            textBox2.AppendText("REQ >> code suicide transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button24_Click(object sender, EventArgs e)
        {
            serialPort1.Write("g"); //retreat child
            textBox2.AppendText("REQ >> code retreat transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button25_Click(object sender, EventArgs e)
        {
            serialPort1.Write("h");  // attack child
            textBox2.AppendText("REQ >> code attack transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void button27_Click(object sender, EventArgs e)
        {
            serialPort1.Write("b");  //emergency stop child
            textBox2.AppendText("REQ >> code emergency stop transmitted");
            textBox2.AppendText(Environment.NewLine);
            try
            {
                textBox2.AppendText(serialPort1.ReadLine());
                textBox2.AppendText(Environment.NewLine);
            }
            catch (TimeoutException)
            {
                textBox2.Text = "Timeout Exception";
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
           

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
