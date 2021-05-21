#ifndef GLOBAL_VARIABLE
#define GLOBAL_VARIABLE

// GLOBAL_VARIABLE
int size_dis = 75;
struct Applicants
{
    int sn;
    char fristname[20];
    char lastname[20];
    char district[20];
    int gender;
    int slc;
    int hseb;
    int ioerank;
    int disable;
    int priority;
};
struct Applicants array[200];

/* The predifined lists of districts */
char *district[75] = {
    "sunsari",
    "kathmandu",
    "lalitpur",
    "bhaktapur",
    "morang",
    "saptari",
    "jhapa",
    "dhankuta",
    "udaypur",
    "siraha",
    "ilam",
    "terathum",
    "panchthar",
    "dhanusa",
    "sinduli",
    "mahotari",
    "sarlahi",
    "kavreplanchowk",
    "rautahat",
    "bara",
    "parsa",
    "makwanpur",
    "chitawan",
    "nawalparasi",
    "tanahu",
    "ramechap",
    "rupandehi",
    "kaski",
    "palpa",
    "kapilbastu",
    "shyangja",
    "ghulmi",
    "nuwakot",
    "peuthan",
    "lamjhung",
    "baglung",
    "dhang",
    "argakhachi",
    "bahke",
    "bardiya",
    "surkhet",
    "kailali",
    "kanchanpur",
    "dhoti",
    "parwat",
    "myagdi",
    "baitadi",
    "bhojpur",
    "khotang",
    "okaldhunga",
    "sankhuwasava",
    "solukhumbu",
    "dolakha",
    "rasuwa",
    "dolakha",
    "sindupalchowk",
    "rasuwa",
    "gorakha",
    "manang",
    "mustang",
    "salyan",
    "rolpa",
    "rukum",
    "doilekh",
    "jajarkot",
    "dolpa",
    "jhumla",
    "humla",
    "mugu",
    "kalikot",
    "bajhang",
    "bajura",
    "accham",
    "darchula",
    "dadeldhura",

};
#endif
