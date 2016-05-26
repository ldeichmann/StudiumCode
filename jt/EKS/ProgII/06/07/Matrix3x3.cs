﻿using System;
using System.Text;

namespace Blatt8
{
    /// <summary>
    /// Klasse fuer quadratische 3x3 Matrizen
    /// 
    /// *******************************************************
    /// Blatt 8 Präsenz-Aufgabe:
    /// Überladen Sie den == Operator so, dass er die übliche
    /// Gleichheit von 3x3 Matrizen implementiert.
    /// Prüfen Sie auf "null". Um dabei keine Endlosrekursion 
    /// zu produzieren müssen Sie die Operanden zuerst auf
    /// (object) casten.
    /// *******************************************************
    /// </summary>
    class Matrix3x3
    {
        private int[,] data;
        public const int size = 3;

        /// <summary>
        /// Initialisiert 3x3 Matrix durch Array
        /// </summary>
        /// <param name="data">Data.</param>
        public Matrix3x3(int[,] data)
        {
            if (data.GetLength(0) == size && data.GetLength(1) == size)
                this.data = data;
            else
                this.data = new int[size, size];
        }

        /// <summary>
        /// Erzeugt die 3x3 Nullmatrix
        /// </summary>
        public Matrix3x3()
        {
            this.data = new int[size, size];
        }

        /// <summary>
        /// Matrixaddition: Komponentenweise
        /// </summary>
        /// <param name="lhs">Linke Seite</param>
        /// <param name="rhs">Rechte Seite</param>
        public static Matrix3x3 operator +(Matrix3x3 lhs, Matrix3x3 rhs)
        {
            int[,] summe;
            if (rhs == null)
                return lhs;
            if (lhs == null)
                return rhs;
            summe = new int[size, size];
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    summe[i, j] = lhs.data[i, j] + rhs.data[i, j];
            return new Matrix3x3(summe);
        }

        /// <summary>
        /// Returns a <see cref="System.String"/> that represents the current <see cref="Blatt8.Matrix3x3"/>.
        /// </summary>
        /// <returns>A <see cref="System.String"/> that represents the current <see cref="Blatt8.Matrix3x3"/>.</returns>
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    sb.AppendFormat(" {0} ", data[i, j]);
                sb.AppendLine();
            }
            return sb.ToString();
        }

        public static bool operator ==(Matrix3x3 m1, Matrix3x3 m2)
        {
            if(m1 == null && m2 == null)
                return false;
            if (m1 == null && m2 != null)
                return false;
            if (m2 == null && m1 != null)
                return false;

            if (m1 != null && m2 != null)
            {
                for (int i = 0; i < size; i++)
                    for (int j = 0; j < size; j++)
                        if (i != j) return false;
                        else return true;
            }
            else
                return false;

            return false;
        }

        public static bool operator !=(Matrix3x3 m1, Matrix3x3 m2)
        {
            return !(m1 == m2);
        }

        public static void Main(string[] args)
        {
            Matrix3x3 A = new Matrix3x3(new int[,] { { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 } });
            Matrix3x3 B = new Matrix3x3(new int[,] { { 1, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } });


            Console.WriteLine("A + B = B + A: {0}", A + B == B + A);
        }
    }
}
