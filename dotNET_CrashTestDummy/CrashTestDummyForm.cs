using GoogleMapsClientInteface;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace dotNET_CrashTestDummy
{
    public partial class CrashTestDummyForm : Form
    {
        public CrashTestDummyForm()
        {
            InitializeComponent();

            tbAddress.Text = "Google Building 44, Mountain View, California, Stati Uniti";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            GoogleMapsAPI googleMapsAPI = new GoogleMapsAPI();

            googleMapsAPI.Address = tbAddress.Text;

            bool retVal = googleMapsAPI.GetCoordinates();

            lblLatitude.Text = (retVal) ? googleMapsAPI.Latitude.ToString() : "Error";

            lblLongitude.Text = (retVal) ? googleMapsAPI.Longitude.ToString() : "Error";
        }
    }
}
