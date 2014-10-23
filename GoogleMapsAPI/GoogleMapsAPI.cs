
// <copyright file="googlemaps.cs" company="AlienTech">
// Copyright (c) 2011, 2111 All Right Reserved
//
// This source is subject to the user Permissive License.
// All other rights reserved.
//
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY 
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
// </copyright>
// <author>user</author>
// <email>maurizio.attanasi@gmail.com</email>
// <blog>http://maurizioattanasi.blogspot.it/</blog>
// <date>27/8/2014</date>
// <summary></summary>

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace GoogleMapsClientInteface
{
    public class GoogleMapsAPI
    {
        /// <summary>
        /// Returns the location latitude
        /// </summary>
        public double Latitude { get; private set; }

        /// <summary>
        /// Returns the location longitude
        /// </summary>
        public double Longitude { get; private set; }

        /// <summary>
        /// Set the desired location address
        /// </summary>
        public string Address { get; set; }

        /// <summary>
        /// Gets the location coordinates from the Google Maps API Web Service
        /// https://developers.google.com/maps/documentation/geocoding/
        /// </summary>
        /// <returns>true on success, false otherwise</returns>
        public bool GetCoordinates()
        {
            if (Address.Length == 0)
                return false;

            var requestUri =
                string.Format("http://maps.googleapis.com/maps/api/geocode/xml?address={0}&sensor=false", Uri.EscapeDataString(Address));

            try
            {
                var request = WebRequest.Create(requestUri);
                var response = request.GetResponse();
                var xdoc = XDocument.Load(response.GetResponseStream());

                var result = xdoc.Element("GeocodeResponse").Element("result");
                var locationElement = result.Element("geometry").Element("location");
                var lat = locationElement.Element("lat").Value;
                var lng = locationElement.Element("lng").Value;

                double latitude = double.NaN, longitude = double.NaN;

                if (double.TryParse(lat, out latitude) && double.TryParse(lng, out longitude))
                {
                    this.Latitude = latitude;
                    this.Longitude = longitude;

                    return true;
                }

                return false;
            }
            catch 
            {
                return false;
            }
        }
    }
}
