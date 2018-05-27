#pragma once

void AttributionFiles(File<Tete> &fTete, File<Jupe> &fJupe, File<Axe> &fAxe);

void RecuperationTete(File<Tete> &fTeteTraite, File<Tete> &fTete, Tete &teteCourante, MT &mt);

void RecuperationAxe(File<Axe> &fAxeTraite, File<Axe> &fAxe, Axe &axeCourante, MA &ma);

void RecuperationJupe(File<Jupe> &fJupeTraite, File<Jupe> &fJupe, Jupe &jupeCourante, MJ &mj);

bool FilesPasPretes(File<Tete> &fTete, File<Tete> &fTeteTraite, File<Jupe> &fJupe, File<Jupe> &fJupeTraite, File<Axe> &fAxe, File<Axe> &fAxeTraite);
