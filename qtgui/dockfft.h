/* -*- c++ -*- */
/*
 * Gqrx SDR: Software defined radio receiver powered by GNU Radio and Qt
 *           http://gqrx.dk/
 *
 * Copyright 2011-2013 Alexandru Csete OZ9AEC.
 *
 * Gqrx is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * Gqrx is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Gqrx; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef DOCKFFT_H
#define DOCKFFT_H

#include <QDockWidget>
#include <QSettings>

namespace Ui {
    class DockFft;
}

/*! \brief Dock widget with FFT settings. */
class DockFft : public QDockWidget
{
    Q_OBJECT

public:
    explicit DockFft(QWidget *parent = 0);
    ~DockFft();

    int fftRate();
    int setFftRate(int fft_rate);

    int fftSize();
    int setFftSize(int fft_size);

    void saveSettings(QSettings *settings);
    void readSettings(QSettings *settings);

signals:
    void fftSizeChanged(int size);   /*! FFT size changed. */
    void fftRateChanged(int fps);    /*! FFT rate changed. */
    void fftSplitChanged(int pct);   /*! Split between pandapter and waterfall changed. */
    void fftAvgChanged(double gain); /*! FFT video filter gain has changed. */
    void resetFftZoom(void);         /*! FFT zoom reset. */
    void gotoFftCenter(void);        /*! Go to FFT center. */
    void gotoDemodFreq(void);        /*! Center FFT around demodulator frequency. */
    void fftColorChanged(const QColor &); /*! FFT color has changed. */
    void fftFillToggled(bool fill);  /*! Toggle filling area under FFT plot. */

private slots:
    void on_fftSizeComboBox_currentIndexChanged(const QString & text);
    void on_fftRateComboBox_currentIndexChanged(const QString & text);
    void on_fftSplitSlider_valueChanged(int value);
    void on_fftAvgSlider_valueChanged(int value);
    void on_resetButton_clicked(void);
    void on_centerButton_clicked(void);
    void on_demodButton_clicked(void);
    void on_colorPicker_colorChanged(const QColor &);
    void on_fillButton_toggled(bool checked);

private:
    Ui::DockFft *ui;
};

#endif // DOCKFFT_H
